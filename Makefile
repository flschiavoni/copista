crop: crop.c
	g++ src/inspect_contour.c \
		src/is_file.c \
		src/print_points.c \
		src/calculate_mass_center.c \
		src/open_image.c \
		src/list_files.c \
		src/find_corners.c \
		src/find_biggest_contour.c \
		src/get_rect_corners.c \
		src/crop_to_contour.c \
		src/crop_score.c \
		src/get_contours.c \
		crop.c -o crop -I. `pkg-config --cflags --libs opencv`

getinfo: getinfo.c
	g++ \
		src/inspect_contour.c \
		src/inspect_image.c \
		src/print_points.c \
		src/is_file.c \
		src/calculate_mass_center.c \
		src/open_image.c \
		src/list_files.c \
		src/find_corners.c \
		src/find_biggest_contour.c \
		src/get_rect_corners.c \
		src/crop_to_contour.c \
		src/crop_score.c \
		src/get_contours.c \
		getinfo.c -o getinfo -I. `pkg-config --cflags --libs opencv`

all: crop getinfo
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/lib/;
	export PKG_CONFIG_PATH=/lib/pkgconfig/;
#	g++ src/open_image.c src/crop_image.c And.c -o And `pkg-config --cflags --libs opencv`
#	g++ And3.c -o And3 `pkg-config --cflags --libs opencv`
	g++ src/inspect_contour.c find_contour.c -o find_contour -I. `pkg-config --cflags --libs opencv`
#	g++ find_contour3.c -o find_contour3 `pkg-config --cflags --libs opencv`
#	g++ find_contour4.c -o find_contour4 `pkg-config --cflags --libs opencv`

