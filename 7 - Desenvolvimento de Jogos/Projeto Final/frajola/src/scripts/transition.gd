extends CanvasLayer
@onready var color_rect = $color_rect

func ready():
	visible = false

func change_scene(path, delay = 2.5):
	var scene_transition = get_tree().create_tween()
	scene_transition.tween_property(color_rect, "treshold", 1.0, 0.5)
	await scene_transition.finished
	Global.goto_scene(path)
