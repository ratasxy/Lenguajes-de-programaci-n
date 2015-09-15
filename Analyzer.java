import java.util.*;
import java.io.*;

public class Analyzer
{
	static final int LETTER = 0;
	static final int DIGIT = 1;
	static final int UNKNOWN = 99;

        static final int EOF = -1;

	static final int INT_LIT = 10;
	static final int IDENT = 11;
        static final int ASSIGN_OP = 20;
        static final int ADD_OP = 21;
        static final int SUB_OP = 22;
        static final int MULT_OP = 23;
        static final int DIV_OP = 24;
        static final int LEFT_PAREN = 25;
	static final int RIGHT_PAREN = 26;


	private static int charClass;
        private static char[] lexeme;
        private static char nextChar;
	private static int lexLen;
	private static int token;
	private static int nextToken;
	private static File file;
	private static FileReader fr; 
	private static BufferedReader br;

        public static void main(String[] args)
        {
		try{
			fr = new FileReader("front.in"); 
			br = new BufferedReader(fr);
		}catch(FileNotFoundException fnfe) { 
            		System.out.println(fnfe.getMessage());
        	} 

		getChar();
		do{
			lex();
		}while(nextToken != EOF);	 			
	}

	public static void addChar()
	{
		if (lexLen <= 98) {
			lexeme[lexLen++] = nextChar;
			lexeme[lexLen] = 0;
                }
		else
		{
			System.out.println("Error - lexeme is too long ");
		}
	}

	public static int lookup(char ch)
	{
		addChar();
		switch(ch){
			case '(':
				nextToken = LEFT_PAREN;
				break;
			case ')':
				nextToken = RIGHT_PAREN;
				break;
			case '+':
				nextToken = ADD_OP;
				break;
			case '-':
				nextToken = SUB_OP;
				break;
			case '*':
				nextToken = MULT_OP;
				break;
			case '/':
				nextToken = DIV_OP;
				break;
			default:
				nextToken = EOF;
				break;
			
		}

		return nextToken;
	}

	public static void getChar()
	{
		int tmp = -1;

		try{
			tmp = br.read();
		}catch(IOException ioe)
    		{
			System.out.println(ioe.getMessage());

   		}
		
		nextChar = (char) -1;
		charClass = EOF;
		if(tmp != -1)
		{
			nextChar = (char) tmp;
			if(Character.isLetter(nextChar))
				charClass = LETTER;
			else if (Character.isDigit(nextChar))
				charClass = DIGIT;
			else
				charClass = UNKNOWN;
		}
	}

	public static void getNonBlank()
	{
		while(Character.isWhitespace(nextChar))
			getChar();
	}	

	public static int lex()
	{
		lexLen = 0;
		getNonBlank();
		
		switch (charClass)
		{
			case LETTER:
				addChar();
				getChar();
				while(charClass == LETTER || charClass == DIGIT){
					addChar();
					getChar();
				}
				nextToken = IDENT;
				break;
			
			case DIGIT:
				addChar();
				getChar();
				while(charClass == DIGIT){
					addChar();
					getChar();
				}
				nextToken = INT_LIT;
				break;
			
			case UNKNOWN:
				lookup(nextChar);
				getChar();
				break;
			
			case EOF:
				nextToken = EOF;
				lexeme[0] = 'E';
				lexeme[1] = 'O';
				lexeme[2] = 'F';
				lexeme[3] = 0;
				break;
		}

		System.out.println("Next token is: " + nextToken + ", Nex lexeme is " + lexeme);

		return nextToken;
	}		

}
