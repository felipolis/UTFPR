class_name GameInit
extends Node2D

func _ready() -> void:
	game_controller.init($Player, $Player/Camera2D)
