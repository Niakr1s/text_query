# Simple Text Query in OOP Paradigm

It's *paragraph* 15.9. *"Text Queries Revisited"* from book *"C++ Primer"*, implemented by myself. I've got much fun while writint this! :)

In addition I implemented parsing incoming text in Query class, so you can print something like this...
```c++
TextQuery tq = TextQuery("file.txt");
Query("(a | b) & c").eval(tq).print();
```

or even more!
```c++
TextQuery tq = TextQuery("file.txt");
Query q = ~Query("(a | b) & c") | Query("~d | e);
q.eval(tq).print();
```