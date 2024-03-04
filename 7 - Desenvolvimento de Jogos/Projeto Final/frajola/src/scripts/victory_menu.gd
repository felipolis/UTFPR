extends CanvasLayer

@onready var transition = $"../transition"
@export var next_level = ""
@export var last_level = false
@onready var portal = $"../portal"
@onready var boss = $"../boss"

# Called when the node enters the scene tree for the first time.
func _ready():
	visible = false
	if boss:
		boss.frajola_has_passed.connect(victory)
	
	if portal:
		portal.frajola_has_passed.connect(victory)


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass
	
func victory():
	# TODO: Setar o score record caso seja a ultima fase
	Global.set_backup()
	visible = true
	
	if last_level:
		Global.has_finished()

func _on_next_btn_pressed():
	if next_level:
		transition.visible = true
		transition.change_scene(next_level)
	else:
		print("Select the scene!")


func _on_back_btn_pressed():
	transition.visible = true
	transition.change_scene("res://src/interfaces/main_menu.tscn")


func _on_quit_btn_pressed():
	get_tree().quit()
