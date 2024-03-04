class_name ScrollingObjetcs
extends Node2D

@export var scroll_speed: float = -100

@onready var _screen_width: int = ProjectSettings.get("display/window/size/viewport_width")

var _start_pos: float

func _ready() -> void:
	_start_pos = position.x

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	position.x += scroll_speed * delta
	
	if abs(position.x - _start_pos) >= _screen_width:
		position.x += _screen_width * -sign(scroll_speed)


	
