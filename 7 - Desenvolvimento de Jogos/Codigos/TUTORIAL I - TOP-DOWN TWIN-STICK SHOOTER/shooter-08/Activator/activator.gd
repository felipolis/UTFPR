class_name Activator
extends Area2D

var _generators: Array[Generator]

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	for node in get_parent().get_children():
		if node is Generator:
			_generators.append(node)


func _on_body_entered(body: Node2D) -> void:
	if body.is_in_group("player"):
		for gen in _generators:
			if gen != null:
				gen.activate()

		queue_free()
