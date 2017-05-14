#compiling the program
CS216PA4:
	g++ *.cpp -o CS216PA4

#defining the object files
OBJECTS = main.o BinaryTree.o
#main.o
HEADERS = BinaryTree.h TreeNode.h

CS216PA4: $(OBJECTS)
	g++ $^ -o CS216PA4
%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@

#cleaning up the trash
clean:
	rm -f *.o CS216PA4
