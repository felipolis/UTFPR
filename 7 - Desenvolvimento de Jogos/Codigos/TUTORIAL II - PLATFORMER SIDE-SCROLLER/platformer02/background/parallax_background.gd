class_name ParallaxBg
extends ParallaxBackground


var layers: Array[ParallaxLayer]

func _ready() -> void:
	for obj in get_children():
		if obj is ParallaxLayer:
			var pal_layer: ParallaxLayer = obj
			layers.append(pal_layer)
			
	

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta) -> void:
	var i: int = 1
	for obj in layers:
		obj.motion_offset.x -= i * 1
		i += 1
		
#	$CloudsTexture1.offset_left += 1
