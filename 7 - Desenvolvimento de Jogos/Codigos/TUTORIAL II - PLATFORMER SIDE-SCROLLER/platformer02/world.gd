extends Node2D

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	$Level/CollisionPolygon2D.polygon = $Level/Polygon2D/CollisionPolygon2D.polygon
