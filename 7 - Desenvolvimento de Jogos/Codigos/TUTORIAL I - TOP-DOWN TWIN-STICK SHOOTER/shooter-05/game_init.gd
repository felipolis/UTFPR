class_name GameInit
extends Node2D

@onready var _player: Player = $Player

func _ready() -> void:
	get_tree().call_group("generator", "set_player", _player)
