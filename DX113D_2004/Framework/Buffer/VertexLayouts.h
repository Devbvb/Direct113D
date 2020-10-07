#pragma once

struct Vertex
{
	Float3 position;

	Vertex() : position(0, 0, 0)
	{}

	Vertex(float x, float y, float z)
		: position(x, y, z)
	{}
};

struct VertexColor
{
	Float3 position;
	Float4 color;
};