(define (same-structure l1 l2)
  (cond
    ((not (list? l1)) (not (list? l2)))
    ((not (list? l2)) #f)
    ((null? l1) (null? l2))
    ((null? l2) #f)
    (else 
      (and (same-structure (car l1) (car l2))
           (same-structure (cdr l1) (cdr l2))
      )
    )
  )
)
