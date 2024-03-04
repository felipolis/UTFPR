extends CanvasLayer

@onready var resume_btn = $menu_holder/resume_btn
@onready var transition = $"../transition"

# Called when the node enters the scene tree for the first time.
func _ready():
	visible = false


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass

func _unhandled_input(event):
	if event.is_action_pressed("ui_cancel"):
		get_tree().paused = true
		visible = true
		# resume_btn.grab_focus()

func _on_resume_btn_pressed():
	get_tree().paused = false
	visible = false

func _on_back_btn_pressed():
	get_tree().paused = false
	visible = false
	Global.get_backup()
	transition.visible = true
	transition.change_scene("res://src/interfaces/main_menu.tscn")


func _on_quit_btn_pressed():
	get_tree().quit()
