extends ColorRect

var treshold = 0.0

func _process(delta):
	material.set("shader_parameter/threshold", treshold)
