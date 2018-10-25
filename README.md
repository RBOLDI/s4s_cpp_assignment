# s4s_cpp_assignment
C++ application that makes a back up of a link using a http-request. this also includes that the application is able to make a backup of the own created REST-API

# Travis link
https://travis-ci.org/RBOLDI/s4s_cpp_assignment.svg?branch=travis

# C++ consumer build
to build the C++ consumer, make sure you have these minimum versions: <br/>
    g++: 4.8 <br/>
    libboost: 1.58 <br/>
    libssl: 1.0.0 <br/>
    cmake: 3.0 <br/>
<br/> 
clone this project using git. go to the direcotry where this project is saved and use the following commands:
<br/>
$ cmake . <br/>
$ make  <br/>
<br/>
to find the executable do: <br/>
$ cd cpp_consumer/Binaries <br/>
in here there should be an executable called backup_src. <br/>
$ ./backup_src

# Server backend 
If you want to make a back up of the backend of the own created REST-API, make sure it's running before running the C++ consumer. <br/>
$ ServerBackEnd/my-api
$ json-server --watch werknemers.json
