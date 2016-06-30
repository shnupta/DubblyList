# DoublyStack
My own doubly linked list structure with some basic functions.

<h2>Main Functions:</h2>

- create_dubbly_list //      Creates a new list
- dub_slap           //      Adds a value to the end of the list.
- dub_shift          //      Adds a value to the front of the list.
- dub_pop            //      Removes the node at the end of the list.
- dub_slice          //      Removes the node at the front of the list.
- dub_length         //      Returns the length of the list.
- dub_clear          //      Clears all the nodes in the list
- dub_destroy        //      Completely deletes the list and all it's nodes
- for_dubbly         //      Iterates through the list (can specify forwards or backwards)


<h2>Basic Usage:</h2>

<h3>create_dubbly_list</h3>
`DubblyList *create_dubbly_list();`

`DubblyList *myList = create_dubbly_list();`

<h3>dub_slap</h3>
`int dub_slap(DubblyList *list, void *value);`

`dub_slap(list, 101);`

<h3>dub_shift</h3>
`int dub_shift(DubblyList *list, void *value);`

`dub_shift(list, 96);`

<h3>dub_pop</h3>
`int dub_pop(DubblyList *list);`

`dub_pop(list);`

<h3>dub_slice</h3>
`int dub_slice(DubblyList *list);`

`dub_slice(list);`

<h3>dub_length</h3>
`int dub_length(DubblyList *list);`

`dub_length(list)`

<h3>dub_clear</h3>
`int dub_clear(DubblyList *list);`

`dub_clear(list);`

<h3>dub_destroy</h3>
`int dub_destroy(DubblyList *list);`

`dub_destroy(list);`

<h3>for_dubbly</h3>
<h4>FORWARD</h4>
```
for_dubbly(list, head, next, cur) {
    printf("%d\n", cur->value);
}
```
<h4>BACKWARD</h4>
```
for_dubbly(list, tail, prev, cur) {
    printf("%d\n", cur->value);
}
```
To prevent redefinition errors when using the loop. Just change the name of the last argument.
