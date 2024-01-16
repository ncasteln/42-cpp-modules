## Reference to const
Constant reference to an object of const type. Important differences from a normal reference:
1) _ref to const_ cannot be used to change the object which refers to.
2) We cannot assign a normal ref to a const object.
3) We cannot re-assign a ref to const to another object.
4) A _ref to const_ can be bound also to a non-const object, to a literal, to other expressions and to an object of different type.
```
*case (1) & (2)*
int	main( void ) {
	int		n = 42;
	int&	nref = n;

	const int	m = 90;
	const int&	mref = m;


	nref = 910;		// this will change the value of n;
	mref = 5;		// error: mref is ref to const

	int&	o = n;	// error: normal ref to const object
	return (0);
}
```
```
*case (3) & (4)*
int	main( void ) {
	int			n = 42;
	const int&	nref = n;				// ref to const to non-const obj
	const int&	lit_ref = 98;			// ref to const to literal
	const int&	expref = nref * 10;		// ref to const to expression

	double		d = 3,14;
	const int&	dref = d;				// ref to const to obj of different type

	int&	invalidexp = nref * 10;		// error: nref is ref to const

	lit_ref = n;						// re-assignation not allowed
	return (0);
}
```

## Pointer to const
They look very similar to references. Here the main features:
1) _ptr to const_ cannot be used to change the object which points to.
2) _ptr to const_ can be re-assigned (while _ref to const_ not).

## Const pointer
A pointer can point to a const object, but can also _be a const itself_. In other words, it will points forever to the same object. Like any other const object, it needs to be initalized. The syntax can be tricky:
```
int	main( void ) {
	const int	n = 42;

	const int*			ptr1 = &n;	// pointer to const
	int* const			ptr2 = &n;	// const pointer
	const int* const	ptr3 = &n;	// const pointer to const

	int* const	ptr4;		// error: needs to be initialized!
	return (0);
}
```
