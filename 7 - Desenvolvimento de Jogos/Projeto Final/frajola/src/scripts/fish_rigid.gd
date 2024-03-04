extends RigidBody2D

func _on_fish_tree_exited():
	queue_free()
