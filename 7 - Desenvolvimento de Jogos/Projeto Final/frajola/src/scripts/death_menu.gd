extends CanvasLayer

@onready var frajola = $"../frajola"
@onready var transition = $"../transition"


# Called when the node enters the scene tree for the first time.
func _ready():
	visible = false
	frajola.frajola_has_died.connect(game_over)

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass

func game_over():
	frajola.queue_free()
	visible = true

func _on_restart_btn_pressed():
	Global._reset_game()
	transition.visible = true
	transition.change_scene("res://src/levels/level_01.tscn")


func _on_back_btn_pressed():
	Global._reset_game()
	transition.visible = true
	transition.change_scene("res://src/interfaces/main_menu.tscn")


func _on_quit_btn_pressed():
	get_tree().quit()
