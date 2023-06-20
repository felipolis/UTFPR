#lang scheme

(define (fat-helper n partial)
    (if (= n 0)
    partial
    (fat-helper (- n 1) (* n partial))))

(define (fat n)
    (fat-helper n 1))