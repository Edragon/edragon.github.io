
# pi-cam-opencv

OpenCV (For Local Processing)

If you want to process the camera feed on the Raspberry Pi itself:

Install dependencies:

    sudo apt update
    sudo apt install python3-opencv

Create a Python script to capture and display the camera feed:

    import cv2

    cap = cv2.VideoCapture(0)  # Open the default camera

    while cap.isOpened():
        ret, frame = cap.read()
        if not ret:
            break
        cv2.imshow("Camera Feed", frame)
        
        # Press 'q' to exit
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    cap.release()
    cv2.destroyAllWindows()

Run the script:

    python3 camera.py