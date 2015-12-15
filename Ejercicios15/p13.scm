(define (union l1 l2)
  (cond ((null? l1) l2)
        ((null? l2) '())
        (else
          (let (
                (h1 (car l1))
                (c1 (cdr l1))
                (h2 (car l2))
                (c2 (cdr l2))
               )
            (cond
              ((< h1 h2) (cons h1 (union c1 l2)))
              ((< h2 h1) (cons h2 (union l1 c2)))
              (else (cons h1 (union c1 c2)))
            )
          )
        )
  )
)
