module p20

let rec pot a b =
    if b = 0 then 1 else
        let t = pot a (b / 2)
        t * t * (if (b % 2) = 0 then 1 else a)
