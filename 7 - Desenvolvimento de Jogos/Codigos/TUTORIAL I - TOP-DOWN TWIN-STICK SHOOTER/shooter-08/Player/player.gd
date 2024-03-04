class_name Player
extends CharacterBody2D

@export var aim: Aim
@export var max_speed: float = 200
@export var acceleration: float = 70
@export var bullet_speed: float = 400
@export var fire_delay: float = 0.10
@export var fire_error: float = 0.08

var _bullet_res: Resource = preload("res://Bullet/bullet.tscn")
var _input_vector: Vector2
var _can_fire: bool = true
var _old_position: Vector2

func _ready() -> void:
	assert(aim, name + ": 'aim' must be provided")


func _process(delta: float) -> void:
	aim.update_position(get_global_position(), get_global_position() - _old_position)
	_old_position = get_global_position()


func _physics_process(_delta: float) -> void:
	_input_vector.x = Input.get_axis("ui_left", "ui_right")
	_input_vector.y = Input.get_axis("ui_up", "ui_down")
	_input_vector = _input_vector.normalized()
	
	#velocity = _input_vector * max_speed
	if _input_vector != Vector2.ZERO:
		velocity = velocity.move_toward(_input_vector * max_speed, acceleration)
	else:
		velocity = velocity.move_toward(Vector2.ZERO, acceleration)		

	move_and_slide()

	#look_at(get_global_mouse_position())
	look_at(aim.get_global_position())
	
	# shooting
	if OS.has_feature("mobile") and _mobile_fire():
		_fire_bullet()
	elif Input.is_action_pressed("fire"):
		_fire_bullet()


func _mobile_fire() -> bool:
	var input_vector2: Vector2 = Vector2.ZERO
	input_vector2.x = Input.get_axis("ui_left2", "ui_right2")
	input_vector2.y = Input.get_axis("ui_up2", "ui_down2")
	return input_vector2 != Vector2.ZERO
	
	
func _fire_bullet():
	if not _can_fire:
		return
	
	var bullet: RigidBody2D = _bullet_res.instantiate()
	bullet.position = $BulletPoint.get_global_position()
	bullet.rotation = rotation
	bullet.apply_impulse(Vector2(bullet_speed,0).rotated(rotation), Vector2())
	get_tree().get_root().add_child(bullet)
	
	_can_fire = false
	await get_tree().create_timer(fire_delay).timeout
	_can_fire = true	
