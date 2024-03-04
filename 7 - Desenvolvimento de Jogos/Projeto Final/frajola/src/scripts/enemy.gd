extends CharacterBody2D

@export var life = 2
@export var patrol_distance = 100
@export var patrol_state : PatrolState = PatrolState.FREE_PATROL

@onready var wall_detector := $wall_detector as RayCast2D
@onready var anim = $anim as AnimationPlayer

@export var enemy_score := 50

enum PatrolState { FREE_PATROL, LIMITED_PATROL, IDLE }

@export var SPEED = 700.0
const JUMP_VELOCITY = -400.0

var direction := 1
var distance_travelled := 0.0  # Variável para rastrear a distância percorrida

# Get the gravity from the project settings to be synced with RigidBody nodes.
var gravity = ProjectSettings.get_setting("physics/2d/default_gravity")

func _ready():
	if patrol_state == PatrolState.IDLE:
		anim.play("idle")

func _physics_process(delta):
	if patrol_state == PatrolState.FREE_PATROL:
		# Add the gravity.
		if not is_on_floor():
			velocity.y += gravity * delta
			
		if wall_detector.is_colliding():
			direction *= -1
			scale.x *= -1
			
		velocity.x = direction * SPEED * delta

		move_and_slide()
	elif patrol_state == PatrolState.LIMITED_PATROL:
		# Adicione a gravidade.
		if not is_on_floor():
			velocity.y += gravity * delta
			
		if wall_detector.is_colliding():
			direction *= -1
			scale.x *= -1
			
		velocity.x = direction * SPEED * delta

		# Atualize a distância percorrida
		distance_travelled += abs(velocity.x) * delta

		# Verifique se a distância percorrida atingiu o limite
		if distance_travelled >= patrol_distance:
			direction *= -1
			scale.x *= -1
			distance_travelled = 0.0

		move_and_slide()
	elif patrol_state == PatrolState.IDLE:
		#anim.play("idle")
		# Adicione a gravidade.
		if not is_on_floor():
			velocity.y += gravity * delta
		
		move_and_slide()


func _on_anim_animation_finished(anim_name):
	if anim_name == "die":
		Global.player_score += enemy_score
		queue_free()
	if anim_name == "hurt":
		anim.play("walk")
		
