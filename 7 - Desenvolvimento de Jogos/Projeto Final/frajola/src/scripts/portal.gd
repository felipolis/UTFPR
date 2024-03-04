extends Area2D

@onready var transition = $"../transition"
@onready var frajola = $"../frajola"

signal frajola_has_passed

# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass


func _on_body_entered(body):
	if body.name == "frajola":
		frajola.queue_free()
		emit_signal("frajola_has_passed")
		
