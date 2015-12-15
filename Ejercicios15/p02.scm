(define (roots a b c)
  (let ((discr (- (* b b) (* 4 a c))) (div (* 2 a)))
    (list
      (if (negative? discr ) 'complex 'real)
      (/ (- (- b) (sqrt discr)) div)
      (/ (+ (- b) (sqrt discr)) div)
    )
  )
)
