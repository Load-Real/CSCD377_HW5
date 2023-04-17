#include "Parasol.h"

unsigned int parasol_vao;

void createParasol()
{ 
	GLfloat parasol_vertices[18][3] = {
		//Steps 5.i and 5.ii
		{0.0, 0.5, 0.0}, //Triangle 1
		{2.0 * cos(radians(0.0)), 0.0,  2.0 * sin(radians(0.0))},
		{2.0 * cos(radians(60.0)), 0.0, 2.0 * sin(radians(60.0))},

		{0.0, 0.5, 0.0}, //Triangle 2
		{2.0 * cos(radians(60.0)), 0.0, 2.0 * sin(radians(60.0))},
		{2.0 * cos(radians(120.0)), 0.0, 2.0 * sin(radians(120.0))},

		{0.0, 0.5, 0.0}, //Triangle 3
		{2.0 * cos(radians(120.0)), 0.0, 2.0 * sin(radians(120.0))},
		{2.0 * cos(radians(180.0)), 0.0, 2.0 * sin(radians(180.0))},

		{0.0, 0.5, 0.0}, //Triangle 4
		{2.0 * cos(radians(180.0)), 0.0, 2.0 * sin(radians(180.0))},
		{2.0 * cos(radians(240.0)), 0.0, 2.0 * sin(radians(240.0))},

		{0.0, 0.5, 0.0}, //Triangle 5
		{2.0 * cos(radians(240.0)), 0.0, 2.0 * sin(radians(240.0))},
		{2.0 * cos(radians(300.0)), 0.0, 2.0 * sin(radians(300.0))},

		{0.0, 0.5, 0.0}, //Triangle 6
		{2.0 * cos(radians(300.0)), 0.0, 2.0 * sin(radians(300.0))},
		{2.0 * cos(radians(0.0)), 0.0,  2.0 * sin(radians(0.0))},

		//Vertices List (for Copy/Paste Purposes)
		//0.0, 0.5, 0.0,										  //O
		//2.0*cos(radians(0.0)), 0.0,  2.0*sin(radians(0.0)),     //A
		//2.0*cos(radians(60.0)), 0.0, 2.0*sin(radians(60.0)),    //B
		//2.0*cos(radians(120.0)), 0.0, 2.0*sin(radians(120.0)),  //C
		//2.0*cos(radians(180.0)), 0.0, 2.0*sin(radians(180.0)),  //D
		//2.0*cos(radians(240.0)), 0.0, 2.0*sin(radians(240.0)),  //E
		//2.0*cos(radians(300.0)), 0.0, 2.0*sin(radians(300.0)),  //F
	};

	GLfloat updated_parasol_vertices[18][3] = {
		//Step 10
		{0.0, 0.5, 0.0}, //Triangle 1
		{2.0 * cos(radians(0.0)), 0.0,  2.0 * sin(radians(0.0))},
		{2.0 * cos(radians(60.0)), 0.0, 2.0 * sin(radians(60.0))},

		{0.0, 0.5, 0.0}, //Triangle 2
		{2.0 * cos(radians(60.0)), 0.0, 2.0 * sin(radians(60.0))},
		{2.0 * cos(radians(120.0)), 0.0, 2.0 * sin(radians(120.0))},

		{0.0, 0.5, 0.0}, //Triangle 3
		{2.0 * cos(radians(120.0)), 0.0, 2.0 * sin(radians(120.0))},
		{2.0 * cos(radians(180.0)), 0.0, 2.0 * sin(radians(180.0))},

		{0.0, 0.5, 0.0}, //Triangle 4
		{2.0 * cos(radians(180.0)), 0.0, 2.0 * sin(radians(180.0))},
		{2.0 * cos(radians(240.0)), 0.0, 2.0 * sin(radians(240.0))},

		{0.0, 0.5, 0.0}, //Triangle 5
		{2.0 * cos(radians(240.0)), 0.0, 2.0 * sin(radians(240.0))},
		{2.0 * cos(radians(300.0)), 0.0, 2.0 * sin(radians(300.0))},

		{0.0, 0.5, 0.0}, //Triangle 6
		{2.0 * cos(radians(300.0)), 0.0, 2.0 * sin(radians(300.0))},
		{2.0 * cos(radians(0.0)), 0.0,  2.0 * sin(radians(0.0))},
	};


	//Step 5.ii
	GLfloat parasol_colors[18][4] = {
		1.0, 0.0, 0.0, 1.0, //Triangle 6 = Red  
		1.0, 0.0, 0.0, 1.0,
		1.0, 0.0, 0.0, 1.0,

		1.0, 1.0, 0.0, 1.0, //Triangle 5 = Yellow
		1.0, 1.0, 0.0, 1.0,
		1.0, 1.0, 0.0, 1.0,

		0.0, 1.0, 0.0, 1.0, //Triangle 4 = Green
		0.0, 1.0, 0.0, 1.0,
		0.0, 1.0, 0.0, 1.0,

		0.0, 0.0, 1.0, 1.0, //Triangle 3 = Blue
		0.0, 0.0, 1.0, 1.0,
		0.0, 0.0, 1.0, 1.0,

		0.0, 1.0, 1.0, 1.0, //Triangle 2 = Cyan
		0.0, 1.0, 1.0, 1.0,
		0.0, 1.0, 1.0, 1.0,

		1.0, 0.0, 1.0, 1.0, //Triangle 1 = Magenta
		1.0, 0.0, 1.0, 1.0,
		1.0, 0.0, 1.0, 1.0,
	};

	glGenVertexArrays(1, &parasol_vao);
	glBindVertexArray(parasol_vao);

	unsigned int handle[2];
	glGenBuffers(2, handle);

	glBindBuffer(GL_ARRAY_BUFFER, handle[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(parasol_vertices), parasol_vertices, GL_STATIC_DRAW);
	//Second index of glVertexAttribPointer is the offset, which is the amount of values you are reading in at a time above
	//So 3 vertices here
	glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);  // Vertex position

	glBindBuffer(GL_ARRAY_BUFFER, handle[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(parasol_colors), parasol_colors, GL_STATIC_DRAW);
	//AND 4 colors here
	glVertexAttribPointer((GLuint)1, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);  // Vertex normal

	glBindVertexArray(0);

}

void drawParasol() {
	glBindVertexArray(parasol_vao);
	glDrawArrays(GL_TRIANGLES, 0, 18);
}
