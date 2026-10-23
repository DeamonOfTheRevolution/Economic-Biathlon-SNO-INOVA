extends TileMap

var start_x = 790
var start_y = 150
var num_of_tree=0
var old_trees=[]
var rand = RandomNumberGenerator.new()
var arr = [Vector2(0,0),Vector2(1,0),Vector2(2,0),Vector2(0,1),Vector2(1,1),Vector2(2,1)]

func _ready():
	var timer = get_node("Timer")
	timer.timeout.connect(_on_timer_timeout)

func _process(delta):
	pass

func _on_timer_timeout():
	var n1 = rand.randi_range(0,5)
	var y_random_const = rand.randi_range(7,25)
	var x_random_const = rand.randi_range(40, 120)
	set_cell(0, Vector2i(start_x, start_y+y_random_const), 1, arr[n1])
	print("set_sell")
	
	num_of_tree+=1
	old_trees.append(Vector2i(start_x, start_y+y_random_const))
	if (num_of_tree>30):
		erase_cell(0,old_trees[0])
		old_trees.remove_at(0)
		print("Removed")
	
	start_x+=x_random_const
	
	





	
	
	
