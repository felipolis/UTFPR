class_name Bullet
extends RigidBody2D

@export var damage: float = 1
@export var not_target: String = "player"

func _on_body_entered(body: Node) -> void:
	if not body.is_in_group(not_target):
		queue_free()
