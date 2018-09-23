# OOP control work 
*Developed by Kyrylo Vasylenko, CSIT-2*

## TASK 1

- Create the most effective (the one that creates the minimum amount of additional objects) representation of Triangle with the help of its points and (or) segments. Keep track of objects. Create a function to construct a Triangle's median with the following signature: const Segment& Triangle::median(const Segment& side) const

My comment: 
Signature was changed from `const Segment& Triangle::median(const Segment& side) const`
to `const Segment& median(const SidePtr) const` for using median method for any side of triangle.

## TASKS 2 and 3

- Create class Calendar, which provides the functionality to determine day of the week by its date.
- Add national celebrations' dates to Calendar.

My comment:
I just added holidays from 2018 year without counting easter and etc.

## TASKS 4 and 5

- Create class Alarm to signal on a particular day and time.
- Make it possible to cancel alarm or repeat it if it's not cancelled during a particular period defined in class.

## TASK 6

- Make it possible to create an Alarm, which will signal every workday (excluding celebrations).

My comment: 
For testing of this tasks I used std::thread,
because good solution is turn off alarm from other thread, 
while he is working in main thread

Yes, I could did it without std::thread, but I think that solution without thread - not beautiful
(asking user between signals should timer make signal again or not and stop him, if not)

## TASK 7

Create parameterized class Pair, which will contain Key and Value.

## TASK 8

- Priority Stack is a stack, which contains Pairs. Create class QuickPushPriorityStack in such a way that operation void push(const Pair&) has O(1) complexity. The last added element with highest (lowest) priority is popped.

My comment:
Done.
The complexity of push operation is O(1).
The complexity of push operation is O(n), where n - stack size.

## TASK 9

- Create class QuickTopPriorityStack in such a way that operations Value top() const і void pop() have O(1) complexity.

My comment: 
Done.
The complexity of push operation is O(n), where n - stack size.
The complexity of push operation is O(1).

## TASK 10

- Create mutual interface for classes from tasks 8 and 9.

My comment: 
linkedPriorityStack.h
For tasks 8-10 I used NVI architecture
For stack I used Node instead array, because I think, that array has too much excess implementation for using him in stack.