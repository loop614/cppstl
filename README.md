TLDR:
Practicing stl data types, all for fun and education

## Requirements
make, c++ compiler, check Makefile

## Quick Start
```console
$ make build
$ make run
```

There was an existing MySQL system and there was a need to switch to ElasticSearch (other database system)
So there were SQL requests and SQL response format of data.
We added ElasticSearch by taking the same input - SQL requests, converting it to ElasticSearch request
Response was in ElasticSearch format, also was converted to the SQL like one.
This way ElasticSearch was implemented without the need to change any other part of the system.

## TODOs:
- place src and includes together
- try out the unordered_map
- example of all c++ pointers
- remove some of the c style pointers
- each new needs a delete
    - instead use unique (shared would be better for more users) pointer using "make_unique" (make_shared) with the variable auto 

