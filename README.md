*This project has been created as part of the 42 curriculum by Youness Bourajli.*

# push_swap

## Description

`push_swap` is a sorting algorithm project focused on sorting a stack of integers using a limited set of stack operations.  
The goal is to sort the data with the minimum possible number of operations.

The program receives a list of integers as arguments and outputs a sequence of instructions that sorts the stack in ascending order.  
Only the following operations are allowed:

- sa, sb, ss
- pa, pb
- ra, rb, rr
- rra, rrb, rrr

The project emphasizes:
- Algorithm design
- Time and space optimization
- Efficient move calculation
- Clean data structure implementation

The chosen strategy for this implementation is the **Turk Algorithm**, which:
- Pushes elements from stack A to stack B
- Sorts a reduced subset
- Calculates optimal reinsertion cost
- Minimizes operations using combined rotations

A bonus program called `checker` is also included.  
It validates a sequence of operations and verifies whether the stack is correctly sorted.

## Instructions

### Compilation

To compile `push_swap`:

	make
	make all

To compile the bonus checker:

	make bonus

Usage

Run push_swap:

./push_swap 4 67 3 87 23

Run checker:

./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23

Or manually:

./checker 4 67 3 87 23

### Technical Overview

	- Data Structure
	- A singly linked list is used to represent stacks.
	- Each node contains:
		- data (original integer)
		- pos (current position in stack)
		- cost_a
		- cost_b
		- total_cost
		- target
		- next
	- Algorithm Steps
		- Parse and validate input
		- Normalize values via indexing
		- Push elements to stack B until 3 remain in A
		- Sort remaining 3 elements
		- Compute target positions and movement costs
		- Select cheapest node to reinsert
		- Perform optimized rotations (rr, rrr)
		- Push back to stack A
		- Final rotation to bring smallest element to top
	- Error Handling
		- The program handles:
			- Non-numeric input
			- Integer overflow
			- Duplicate values
			- Invalid instructions (checker)
			- Memory allocation failure
			- In case of error, Error is printed to stderr.



## Resources

Algorithm References
- TURK algorithm from Medium:
	
	LINK : https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a

Stack data structures

Linked list manipulation

Sorting algorithms (Insertion, QuickSort concepts)

Rotation-based optimization strategies

42 push_swap subject documentation

AI Usage Disclosure

- AI assistance was used for:

	Conceptual clarification of the Turk Algorithm

	Debugging logical errors in cost calculation

	Reviewing code safety and memory management practices

	Improving README clarity and structure
	
	LINK : https://chatgpt.com/g/g-p-698c3fc26fb08191847dc4fa4fedbc9b-homework/c/698c40d4-6eac-8331-9170-0658020ef20e
