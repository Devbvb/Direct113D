#pragma once

struct Vertex
{
	Float3 position;

	Vertex() : position(0, 0, 0)
	{
	}

	Vertex(float x, float y, float z)
		: position(x, y, z)
	{}
};

struct VertexColor
{
	Float3 position;
	Float4 color;

	VertexColor() : position(0, 0, 0), color(1, 1, 1, 1)
	{
	}
};

struct VertexUV
{
	Float3 position;
	Float2 uv;

	VertexUV() : position(0, 0, 0), uv(0, 0)
	{
	}
};

struct VertexUVNormal
{
	Float3 position;
	Float2 uv;
	Float3 normal;

	VertexUVNormal() : position(0, 0, 0), uv(0, 0), normal(0, 0, 0)
	{
	}
};