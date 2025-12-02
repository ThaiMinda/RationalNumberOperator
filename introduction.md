## Warnings

This program is supported by C99 and later standards.

This program defines 3 common functions: `min()`, `lcm()` and `gcd()`. You should confirm that they do not conflict with your own functions.

## Using Instructions

### Declaration

Use `struct qNum` to declare a rational number. Arrays are also supported.

```C
  struct qNum a ;
  struct qNum b[100] ;
  struct qNum c[100][100] ;
```

### Input

Use function `qScan()` to input the value of a rational number. You should enter according to the following format strictly.

```C
  struct qNum a ;
  a = qScan() ;
```

Integer: Enter the original appearance. `0` for zero, `3` for positive three, `-4` for negative four, etc.

Fraction: Enter the numerator and denominator, separated by `/`. If the number is negative, `-` should be at the forefront. `1/2` for positive half, `8/7` for positive eight seventh, and `-3/5` for negative three fifth, etc. In addition, input like `2/4` is also supported. The program will make a reduction automatically.

### Constant Definition

Use function `qDefine()` to define a constant rational number. The format is the same as the input.

```C
	struct qNum a ;
	a = qDefine("2/5") ;
```

### Output

Use function `qPrint()` to output the value of a rational number. The format is the same as the input.

```C
  struct qNum a ;
  a = qScan() ;
  qPrint(a) ;
```

### Addition

Use function `qAdd()` to get the sum of two rational numbers.

```C
  struct qNum a , b , c ;
  a = qScan() ;
  b = qScan() ;
  c = qAdd(a,b) ;
  qPrint(c) ;
```

### Subtraction

Use function `qSub()` to get the difference of two rational numbers.

```C
  struct qNum a , b , c ;
  a = qScan() ;
  b = qScan() ;
  c = qSub(a,b) ;
  qPrint(c) ;
```

### Multiplication

Use function `qMul()` to get the product of two rational numbers.

```C
  struct qNum a , b , c ;
  a = qScan() ;
  b = qScan() ;
  c = qMul(a,b) ;
  qPrint(c) ;
```

### Division

Use function `qDiv()` to get the quotient of two rational numbers.

If divisor is zero, there will be a messege  `Error!` on the screen and the result will be zero.

Alternatively, you can modify the reaction.

```C
  struct qNum a , b , c ;
  a = qScan() ;
  b = qScan() ;
  c = qDiv(a,b) ;
  qPrint(c) ;
```

### Others

There are two functions `qOpp()` and `qRec()` to get the opposite number and the reciprocal number. They are designed for subtraction and division, but you can also use them proactively.

If `qRec()` receive zero, the reaction is the same as division.

```C
  struct qNum a , b , c ;
  a = qScan() ;
  b = qOpp(a) ;
  c = qRec(a) ;
  qPrint(b) ;
  putchar(' ') ;
  qPrint(c) ;
```

## Principles

### Basic Structure

This program defines a structure `qNum` to storage a rational number.

```C
struct qNum{
	int nume ;
	int deno ;
	int sign ;
};
```

`qNum` has 3 members: `nume`, `deno` and `sign`. `nume` represents the numerator, `deno` represents the denominator, and `sign` represents the polarity.

Under normal circumstances, `nume` and `deno` should be positive integers, and `nume/deno` should be irreducible. Especially, if `nume/deno` is an integer, `deno` should be 1.

As a mark of polarity, `sign` should be 1, -1 or 0. Especially, if `sign` is 0, `nume` and `deno` should be 0 and 1.

Every rational number has its sole form. For example, zero is `(0,1,0)`, positive two is `(2,1,1)`, negative six is `(6,1,-1)`, positive two third is `(2,3,1)`, negative one eighth is `(1,8,-1)`, etc. (Format: `(nume,deno,sign)`)

By using `qNum`, it is possible to accurately represent a large amount of rational numbers.

To avoid breaking the above rules, you should entirely use the functions included in the program to change the values of `qNum`. Do not change a member individually.
