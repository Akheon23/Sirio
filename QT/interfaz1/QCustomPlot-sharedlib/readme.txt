Compiling QCustomPlot as shared library:
  - Make sure the QCustomPlot source files (qcustomplot.h/.cpp) are in the directory above sharedlib. 
  - Run qmake; make; in the sharedlib directory. This will create two library versions: qcustomplot for release mode and qcustomplotd for debug mode.
    For example, on Unix this will create libqcustomplot.so and libqcustomplotd.so and some softlink files to those shared library files.
    
Compiling an application that uses the shared library:
  - Copy all created library/softlink files from the previous step to the sharedlib-demo directory
  - run qmake; make; in the sharedlib-demo directory. This will build the application.
  
Running the application:
  - Make sure the application can find the shared library files.
    Under MS Windows it is sufficient to have the files in the same directory as the executable files.
    On Unix you have at least two options: You can specify the current directory in the LD_LIBRARY_PATH variable (call in
    terminal: "export LD_LIBRARY_PATH=." before launching the application). This is useful for testing if it works. The other option is
    to install the library files to one of the default locations for shared objects: /usr/local/lib or /usr/lib for example.
  - Launch the application.

