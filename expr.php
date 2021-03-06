<?php


class Parser
{

    /* Character classes */
    const EOF = -1;
    const LETTER = 0;
    const DIGIT = 1;
    const POINT = 2;
    const INVALID = 98;
    const UNKNOWN = 99;

    /* Token codes */
    const INT_LIT = 10;
    const IDENT = 11;
    const ASSIGN_OP = 20;
    const ADD_OP = 21;
    const SUB_OP = 22;
    const MULT_OP = 23;
    const DIV_OP = 24;
    const LEFT_PAREN = 25;
    const RIGHT_PAREN = 26;

    private $nextToken;
    private $nextChar;
    private $charClass;
    private $lexeme;
    private $file;

    public function __construct($file)
    {
        $this->file = @fopen($file, "r");;
    }

    public function main()
    {
        $this->getChar();

        do {
            $this->lex();
            $this->expr();
        } while ($this->nextToken != self::EOF);
    }

    public function lookup($ch)
    {
        $this->addChar();

        switch ($ch) {
            case '(':
                $this->nextToken = self::LEFT_PAREN;
                break;

            case ')':
                $this->nextToken = self::RIGHT_PAREN;
                break;

            case '+':
                $this->nextToken = self::ADD_OP;
                break;

            case '-':
                $this->nextToken = self::SUB_OP;
                break;

            case '*':
                $this->nextToken = self::MULT_OP;
                break;

            case '/':
                $this->nextToken = self::DIV_OP;
                break;

            default:
                $this->nextToken = self::EOF;
                break;
        }
    }

    public function addChar()
    {
        $this->lexeme .= $this->nextChar;
    }

    public function getChar()
    {
        $this->charClass = self::EOF;

        if (!feof($this->file)) {
            $this->nextChar = fgetc($this->file);
            if (ctype_alpha($this->nextChar))
                $this->charClass = self::LETTER;

            else if (is_numeric($this->nextChar))
                $this->charClass = self::DIGIT;

            else if ($this->nextChar == ".")
                $this->charClass = self::POINT;

            else $this->charClass = self::UNKNOWN;
        }
    }

    public function getNonBlank()
    {
        while (ctype_space($this->nextChar))
            $this->getChar();
    }

    public function lex()
    {
        $this->lexeme = "";
        $this->getNonBlank();

        switch ($this->charClass) {
            case self::LETTER:
                do {
                    $this->addChar();
                    $this->getChar();
                } while ($this->charClass == self::LETTER || $this->charClass == self::DIGIT);

                $this->nextToken = self::IDENT;
                break;

            case self::DIGIT:
                $pCount = 0;
                do {
                    if ($this->charClass == self::POINT)
                        $pCount++;

                    $this->addChar();
                    $this->getChar();
                } while ($this->charClass == self::DIGIT || ($this->charClass == self::POINT));

                $this->nextToken = self::INT_LIT;

                if($pCount > 1)
                    $this->nextToken = self::INVALID;

                break;

            case self::EOF:
                $this->nextToken = self::EOF;
                $this->lexeme = "EOF";
                break;

            case self::UNKNOWN:
                $this->lookup($this->nextChar);
                $this->getChar();
                break;
        }

        echo "Next token is: $this->nextToken, Next lexeme is $this->lexeme\n";

        return $this->nextToken;
    }

    /* expr
     *  Parses strings in the language generated by te rule:
     *  <expr> -> <term> {(+ | -) <term>}
     * */
    public function expr()
    {
        echo "Enter <expr>\n";

        $this->term();

        while ($this->nextToken == self::ADD_OP || $this->nextToken == self::SUB_OP) {
            $this->lex();
            $this->term();
        }

        echo "Exit <expr>\n";
    }

    /* term
     *  Parses strings in the language generated by the rule:
     *<term> -> <factor> {(* | /) <factor>)
     */
    public function term()
    {

        echo "Enter <term>\n";
        /* Parse the first factor */
        $this->factor();

        /* As long as the next token is * or /, get the
        next token and parse the next factor */
        while ($this->nextToken == self::MULT_OP || $this->nextToken == self::DIV_OP) {
            $this->lex();
            $this->factor();
        }
        echo "Exit <term>\n";
    }

    /* factor
     *Parses strings in the language generated by the rule:
     *<factor> -> id | int_constant | ( <expr )
     */
    public function factor()
    {
        echo "Enter <factor>\n";
        /* Determine which RHS */
        if ($this->nextToken == self::IDENT || $this->nextToken == self::INT_LIT) {
            $this->lex();
        }
        else {
            if ($this->nextToken == self::LEFT_PAREN) {
                $this->lex();
                $this->expr();
                if ($this->nextToken == self::RIGHT_PAREN)
                    $this->lex();
                else
                    $this->error();
            }
            else {
                $this->error();
            }
        }

        echo "Exit <factor>\n";
    }

    public function error()
    {
        echo "A error ocurred\n";
    }
}
