class_name Player
extends CharacterBody2D

const SPEED = 175.0
const JUMP_VELOCITY = 300.0

@onready var _animated_sprite: AnimatedSprite2D = $AnimatedSprite2D
@export var _can_spin: bool = false

var gravity: int = ProjectSettings.get_setting("physics/2d/default_gravity")
var _double_jump: bool = false
var _direction: float = 0

func _physics_process(delta: float) -> void:
	# Add the gravity.
	velocity.y += gravity * delta

	if is_on_floor():
		_double_jump = false	
		
	# Handle Jump.
	if Input.is_action_just_pressed("jump") and (is_on_floor() or not _double_jump):
		velocity.y = JUMP_VELOCITY * up_direction.y
		if not is_on_floor():
			_double_jump = true
		
	if Input.is_action_just_pressed("gravity"):
		gravity = -gravity
		up_direction.y = -up_direction.y

	var input := Input.get_axis("move_left", "move_right")
	if input:
		velocity.x = input * SPEED
		_direction = input
	else:
		velocity.x = move_toward(velocity.x, 0, SPEED)
		
	animate_player()
	move_and_slide()


func animate_player() -> void:
	# on ground
	if is_on_floor():
		if velocity.x == 0:
			_animated_sprite.play("idle")
		else:
			_animated_sprite.play("run")
		_animated_sprite.rotation = 0	
	else:	
		if not _can_spin:
			# jump and fall animations
			if velocity.y < 0:
				_animated_sprite.play("jump")
			else:
				_animated_sprite.play("fall")
		# rotate when double jumping
		else:
			_animated_sprite.play("fall")
			if _double_jump:
				_animated_sprite.play("spin")
				if _direction >= 0:
					_animated_sprite.rotation += 0.4
				else:
					_animated_sprite.rotation -= 0.4
		
	if _direction > 0:
		_animated_sprite.flip_h = false
	else:
		_animated_sprite.flip_h = true
		
	if gravity > 0:
		_animated_sprite.flip_v = false
	else:
		_animated_sprite.flip_v = true
