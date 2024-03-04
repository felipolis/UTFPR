class_name Aim
extends Sprite2D

@export var mouse_speed: float = 0.75
@export var joy_speed: float = 3

var _next_pos: Vector2
var _ref_pos: Vector2
var _radius: float

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	Input.set_mouse_mode(Input.MOUSE_MODE_CAPTURED)
	_next_pos = get_global_position()


func update_position(ref_pos: Vector2, ref_offset: Vector2) -> void:
	_get_joy_input()
	_ref_pos = ref_pos
	
	var direction: Vector2 = _ref_pos - _next_pos
	if direction.length() > _radius:
		_next_pos = _ref_pos - direction.normalized() * _radius
	
	_next_pos += ref_offset
	set_global_position(_next_pos)


func _move_pos(input_vector: Vector2, speed: float) -> void:
	var pos: Vector2 = get_global_position()
	pos += input_vector * speed
	_next_pos = pos


func _input(event: InputEvent) -> void:
	if OS.has_feature("mobile"):
		return

	if event is InputEventMouseMotion and event.relative.length() > 0.5:
		_radius = 150
		_move_pos(event.relative, mouse_speed)
	
	
func _get_joy_input() -> void:
	var input_vector2: Vector2 = Vector2.ZERO
	input_vector2.x = Input.get_axis("ui_left2", "ui_right2")
	input_vector2.y = Input.get_axis("ui_up2", "ui_down2")
	input_vector2 = input_vector2.normalized()
	
	if input_vector2.length() >= 0.3:
		_radius = 75
		_move_pos(input_vector2*_radius, joy_speed)

#override
#func _draw() -> void:
#	draw_line(Vector2.ZERO, to_local(_ref_pos), Color(1,0,0,0.3), 1)
