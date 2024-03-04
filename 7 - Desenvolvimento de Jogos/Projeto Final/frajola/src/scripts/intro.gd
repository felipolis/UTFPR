extends Control


# Called when the node enters the scene tree for the first time.
func _ready():
	await get_tree().create_timer(5).timeout
	Global.goto_scene("res://src/interfaces/main_menu.tscn")


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass
