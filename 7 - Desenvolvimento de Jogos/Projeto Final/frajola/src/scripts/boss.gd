extends CharacterBody2D

@export var life = 2

@onready var anim = $anim as AnimationPlayer
@export var boss_score := 1000
@onready var transition = $"../transition"
@export var next_level = ""

const SPEED = 3000.0
const JUMP_VELOCITY = -400.0
var direction := 1
var _frajola: CharacterBody2D = null
var gravity = ProjectSettings.get_setting("physics/2d/default_gravity")
const JUMP_DISTANCE_THRESHOLD = 100.0

var current_level
signal frajola_has_passed

var time_stuck = 0.0  # Variável para rastrear o tempo em que o inimigo está preso
const MAX_TIME_STUCK = 2.0  # Tempo máximo permitido para estar preso antes de pular

func _ready():
	current_level = Global.get_last_level()

func _physics_process(delta):
	if _frajola != null:
		# Calcula a direção para o jogador
		var direction_to_player = (_frajola.global_position - global_position).normalized()
		
		# Define a direção do boss
		if direction_to_player.x > 0:
			if direction == -1:
				scale.x *= -1
				direction = 1
		else:
			if direction == 1:
				scale.x *= -1
				direction = -1
		
		# Verifica se o jogador está acima do inimigo e longe o suficiente
		if _frajola.global_position.y < global_position.y - JUMP_DISTANCE_THRESHOLD and is_on_floor():
			velocity.y = JUMP_VELOCITY
		else:
			# Adiciona a gravidade
			if not is_on_floor():
				velocity.y += gravity * delta
		
		# Verifica se o inimigo está preso horizontalmente
		if abs(velocity.x) < 1.0:
			time_stuck += delta
			if time_stuck > MAX_TIME_STUCK:
				# Se o inimigo estiver preso por muito tempo, faça-o pular
				velocity.y = JUMP_VELOCITY
				time_stuck = 0.0  # Reinicie o tempo preso
		
		velocity.x = direction * SPEED * delta
		move_and_slide()
	else:
		anim.play('idle')
		
		if not is_on_floor():
			velocity.y += gravity * delta
		
		velocity.x = 0 * SPEED * delta

		move_and_slide()

func _on_anim_animation_finished(anim_name):
	if anim_name == "die":
		Global.player_score += boss_score
		queue_free()
		emit_signal("frajola_has_passed")
		_frajola.queue_free()
	if anim_name == "hurt":
		anim.play("walk")
		
func set_frajola(instance):
	_frajola = instance
