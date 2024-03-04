class_name Enemy
extends CharacterBody2D

@export var min_speed: float = 50
@export var max_speed: float = 100
@export var health: float = 1
@export var direction_error: float = 50

var _player: Player
var _speed: float = randf_range(min_speed, max_speed)
var _motion: Vector2

signal health_depleted

# dependency injection of Player instance
func set_player(player: Player):
	_player = player
	#print(_player.name)
	
	
func _physics_process(_delta: float) -> void:
	_motion = _player.get_global_position() - get_global_position()
	velocity = _motion.normalized() * _speed
	move_and_slide()


func _hit(bullet: Bullet) -> void:
	health -= bullet.damage
	
	if health <= 0:
		emit_signal("health_depleted")
		queue_free()


func _on_hit_box_body_entered(body: Node2D) -> void:
	if body.is_in_group("bullet"):
		_hit(body)
