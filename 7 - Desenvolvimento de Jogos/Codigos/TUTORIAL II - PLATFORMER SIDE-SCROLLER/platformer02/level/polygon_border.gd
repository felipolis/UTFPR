@tool
class_name PolygonBorder
extends Polygon2D

@export var outline_color: Color = Color("522b08"):
	set(value):
		outline_color = value
	get:
		return outline_color

@export var line_width: float = 2.0:
	set(value):
		line_width = value

func _draw():
	draw_polyline(get_polygon(), outline_color, line_width)
