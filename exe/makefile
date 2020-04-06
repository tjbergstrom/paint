all : paint

paint : paint.o Application.o Frame.o Button.o Color.o DotTool.o Tool.o EraserTool.o TabMenu.o UI.o SquareTool.o PencilTool.o StraightLineTool.o
	g++ -o paint paint.o Application.o Frame.o Button.o Color.o DotTool.o Tool.o EraserTool.o TabMenu.o UI.o SquareTool.o PencilTool.o StraightLineTool.o -lsfml-window -lsfml-system -lsfml-graphics -lsfml-audio

paint.o : paint.cpp
	g++ -c paint.cpp

Application.o : Application.cpp Application.hpp
	g++ -c Application.cpp

Frame.o : Frame.cpp Frame.hpp
	g++ -c Frame.cpp

Button.o : Button.cpp Button.hpp
	g++ -c Button.cpp

Color.o : Color.cpp Color.hpp
	g++ -c Color.cpp

DotTool.o : DotTool.cpp DotTool.hpp
	g++ -c DotTool.cpp

Tool.o : Tool.cpp Tool.hpp
	g++ -c Tool.cpp

EraserTool.o : EraserTool.cpp EraserTool.hpp
	g++ -c EraserTool.cpp

TabMenu.o : TabMenu.cpp TabMenu.hpp
	g++ -c TabMenu.cpp

UI.o : UI.cpp UI.hpp
	g++ -c UI.cpp

SquareTool.o : SquareTool.cpp SquareTool.hpp
	g++ -c SquareTool.cpp

PencilTool.o : PencilTool.cpp PencilTool.hpp
	g++ -c PencilTool.cpp

StraightLineTool.o : StraightLineTool.cpp StraightLineTool.hpp
	g++ -c StraightLineTool.cpp

clean : 
	rm -f *.o *.gch paint
