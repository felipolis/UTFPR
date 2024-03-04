extends CharacterBody2D

const SPEED = 100.0
const JUMP_FORCE = -400.0

var gravity = ProjectSettings.get_setting("physics/2d/default_gravity")
var is_jumping := false
var direction
var is_hurted := false
var knockback_vector := Vector2.ZERO

@onready var animation := $anim as AnimatedSprite2D
@onready var remote_tranform = $remote as RemoteTransform2D
@onready var collision = $collision
@onready var hitbox = $hurtbox/collision
@onready var hurtbox_collision = $hurtbox/collision
@export var ball_speed: float = 400
@onready var ball_point = $ball_point
@onready var jump_sfx = $jumpSFX
@onready var hurt_sfx = $hurtSFX
@onready var control = $"../HUD/control"
@onready var shot_sfx = $shotSFX


var ball_res = preload("res://src/prefabs/ball.tscn")

signal frajola_has_died

func _ready():
	control.time_is_up.connect(kill)

func kill():
	emit_signal("frajola_has_died")

func _physics_process(delta):
	# Add the gravity.
	if not is_on_floor():
		velocity.y += gravity * delta
	# Handle Jump.
	if Input.is_action_just_pressed("ui_accept") and is_on_floor():
		velocity.y = JUMP_FORCE
		is_jumping = true
		jump_sfx.play()
	elif is_on_floor():
		is_jumping = false
	
	if Input.is_action_just_pressed("ui_down"):
		collision.disabled = true
		await get_tree().create_timer(0.07).timeout
		collision.disabled = false
	
	if Input.is_action_just_pressed("atack"):
		if Global.player_bullets > 0:
			shot_sfx.play()
			var ball: RigidBody2D = ball_res.instantiate()
			ball.position = ball_point.get_global_position()
			ball.rotation = rotation
			if animation.scale.x == 1:
				ball.apply_impulse(Vector2(ball_speed,0).rotated(rotation), Vector2())
			else:
				ball.apply_impulse(Vector2(-ball_speed,0).rotated(rotation), Vector2())
			get_tree().get_root().add_child(ball)
			Global.player_bullets -= 1
		else:
			pass

	# Get the input direction and handle the movement/deceleration.
	# As good practice, you should replace UI actions with custom gameplay actions.
	direction = Input.get_axis("ui_left", "ui_right")
	if direction:
		velocity.x = direction * SPEED
		animation.scale.x = direction
		collision.position.x = -direction * 4
		hurtbox_collision.position.x = -direction * 4
		if direction == 1:
			$ray_right.position.x = 5
			$ray_left.position.x = -13
			ball_point.position.x = 5
		elif direction == -1:
			$ray_right.position.x = 13
			$ray_left.position.x = -5
			ball_point.position.x = -5
			
	else:
		velocity.x = move_toward(velocity.x, 0, SPEED)

	if knockback_vector != Vector2.ZERO:
		velocity = knockback_vector
		
	_set_state()
	move_and_slide()
	
	for platforms in get_slide_collision_count():
		var collision = get_slide_collision(platforms)
		if collision.get_collider().has_method("has_collided_with"):
			collision.get_collider().has_collided_with(collision, self)
	

func _set_state():
	var state = "idle"
	
	if !is_on_floor():
		state = "jump"
	elif direction != 0:
		state = "run"
		
	if is_hurted:
		state = "hurt"
	
	if animation.name != state:
		animation.play(state)
		

func _on_hurtbox_body_entered(body):
	if $ray_right.is_colliding():
		take_damage(Vector2(-200, -200))
	elif $ray_left.is_colliding():
		take_damage(Vector2(200, -200))
		

func take_damage(knockback_force := Vector2.ZERO, duration := 0.25):
	hurt_sfx.play()
	if Global.player_life > 0:
		Global.player_life -= 1
		
	if Global.player_life <= 0:
		# queue_free()
		emit_signal("frajola_has_died")
	
	if knockback_force != Vector2.ZERO:
		knockback_vector = knockback_force
		
		var knockback_tween := get_tree().create_tween()
		knockback_tween.parallel().tween_property(self, "knockback_vector", Vector2.ZERO, duration)
		animation.modulate = Color(1,0,0,1)
		knockback_tween.parallel().tween_property(animation, "modulate", Color(1,1,1,1), duration)
		
		is_hurted = true
		await get_tree().create_timer(.3).timeout
		is_hurted = false
		
func follow_camera(camera):
	var camera_path = camera.get_path()
	remote_tranform.remote_path = camera_path

func _input(event):
	if event is InputEventScreenTouch:
		if Input.is_action_just_pressed("ui_accept") and is_on_floor():
			velocity.y = JUMP_FORCE
			is_jumping = true
		elif is_on_floor():
			is_jumping = false


func _on_head_collider_body_entered(body):
	if body.has_method("break_sprite"):
		body.hitpoints -= 1
		if body.hitpoints < 0:
			body.break_sprite()
		else:
			body.animation_player.play("hit")
			body.create_fish()
