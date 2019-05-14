# Ways to Get Input in C++

## 1. `cin`

* `cin` uses `string` as input buffer.  
* parsing will be ended by *space*, *line break*, and *TAB*, etc

sample:

```cpp
#include <iostream>
#include <string>

...
...

string buffer;
cin >> buffer;

cout << "Your input: " << buffer << endl;

// or, print by printf()
printf("echo: %s\n", buffer.c_str()); // %s is used for C-style char[]
```

get multiple input:

```cpp
string name;
int age;

cin >> name >> age;
```

## 2. `getline()`

* `getline()` using `string` as input buffer
* accept *space* and *TAB*
* ended by *line break* and discard it

sample:

```cpp
#include <iostream>
#include <string>

...
...

string buffer;

getline(cin, buffer);

cout << "Your input:" << buffer;
```