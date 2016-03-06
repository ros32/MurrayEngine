DIRS = MurrayEngine Implementation

default:
	cd MurrayEngine; $(MAKE)
	cd Implementation; $(MAKE)

clean:
	-for d in $(DIRS); do (cd $$d; $(MAKE) clean); done
