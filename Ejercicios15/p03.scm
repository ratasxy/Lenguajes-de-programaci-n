(define (roots a b c)
  (let ((discriminante (- (* b b) (* 4 a c))) (div (* 2 a)))
    (list
      (cond
        ((negative? discriminante) 'complejo)
        (else 'real)
      )
      (/ (- (- b) (sqrt discriminante)) div)
      (/ (+ (- b) (sqrt discriminante)) div)
    )
  )
)
