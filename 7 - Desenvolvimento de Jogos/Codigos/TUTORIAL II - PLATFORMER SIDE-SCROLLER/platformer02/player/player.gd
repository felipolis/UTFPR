class_name Player
extends CharacterBody2D

const SPEED = 200.0
const ACCELERATION = 500
const FRICTION = 600
const JUMP_VELOCITY = 370.0
const JUMP_VELOCITY_MIN = JUMP_VELOCITY/3

@onready var _animated_sprite: AnimatedSprite2D = $AnimatedSprite2D
@onready var _coyote_timer: Timer = $CoyoteTimer
@onready var _weapon: Weapon = $AnimatedSprite2D/Weapon

var gravity: int = ProjectSettings.get_setting("physics/2d/default_gravity")
var _double_jump: bool = false
var _direction: float = 1
var _start_position: Vector2


func _ready() -> void:
	_start_position = position
	

func _physics_process(delta: float) -> void:
	apply_gravity(delta)
	
	# handle player movements
	handle_jump()
	handle_gravity()
	handle_movement(delta)
			
	animate_player()
	
	var was_on_floor = is_on_floor()
	move_and_slide()
	if was_on_floor and not is_on_floor() and velocity.y >= 0:
		_coyote_timer.start()


func apply_gravity(delta: float):
	velocity.y += gravity * delta


func handle_jump() -> void:
	if is_on_floor():
		_double_jump = false

	if Input.is_action_just_pressed("jump"):
		if is_on_floor() or not _double_jump or _coyote_timer.time_left > 0:
			velocity.y = JUMP_VELOCITY * up_direction.y
			if not is_on_floor() and _coyote_timer.time_left == 0:
				_double_jump = true
	else:
		if Input.is_action_just_released("jump"):
			if velocity.y < JUMP_VELOCITY_MIN * up_direction.y:
				velocity.y = JUMP_VELOCITY_MIN * up_direction.y	


func handle_gravity() -> void:
	if Input.is_action_just_pressed("gravity"):
		gravity = -gravity
		up_direction.y = -up_direction.y


func handle_movement(delta: float) -> void:
	var input := Input.get_axis("move_left", "move_right")
	if input:
#		velocity.x = input * SPEED
		velocity.x = move_toward(velocity.x, input * SPEED, ACCELERATION * delta)
		_direction = sign(input)
	else:
		velocity.x = move_toward(velocity.x, 0, FRICTION * delta)


func animate_player() -> void:
	if is_on_floor():
		if velocity.x == 0:
			_animated_sprite.play("idle")
		else:
			_animated_sprite.play("run")
		_animated_sprite.rotation = 0
	else:	
		_animated_sprite.play("fall")
		if _double_jump:
			_animated_sprite.play("spin")
			_animated_sprite.rotation += 0.4 * -_direction * up_direction.y
		
#	_animated_sprite.flip_h = false if _direction > 0 else true
	_animated_sprite.scale.x = _direction
#	_animated_sprite.flip_v = false if gravity > 0 else true
	_animated_sprite.scale.y = sign(gravity)


func _on_hurt_box_area_entered(area: Area2D) -> void:
	position = _start_position


func _on_item_collector_area_entered(area: Area2D) -> void:
	print("item collecteced!")
	area.queue_free()
