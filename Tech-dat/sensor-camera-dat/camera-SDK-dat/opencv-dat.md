
# opencv-dat

- [[camera-sdk-dat]] 


## demo code 

    # run this on Linux PC with opencv-python module

    import cv2

    dropped = 0 # drop frames count

    # 192.168.4.44 - AIT esp32s
    # Change this to your board IP
    # http-based streaming not RTSP
    vid = cv2.VideoCapture('http://192.168.4.97/ait/Hi-AIT-123') # open webcam capture

    while True:
        ret, frame = vid.read() # get frame-by-frame
        #print(vid.isOpened(), ret)
        if frame is not None:
            if dropped > 0: dropped = 0 # reset
            cv2.imshow('Video-44',frame) # display frame
            if cv2.waitKey(22) & 0xFF == ord('q'): # press q to quit
                break
        else:
            dropped += 1
            if dropped > 100:
            print("Server is down")
            break

    # Done, clear all resources
    vid.release()
    cv2.destroyAllWindows()
    print("Video stop")

## face detection 

    import cv2

    dropped = 0 # drop frames count
    from cvzone import FaceDetectionModule

    face = FaceDetectionModule.FaceDetector()

    # Change this to your board IP
    # url = 'http://192.168.4.74/free/Hi-Nove-La'a # freenove
    # url = 'http://192.168.4.70/xiao/Hi-Xiao-Ling' # xio
    # url = 'http://192.168.4.71/lily/Hi-Lily-Goen' # lilygo
    url = 'http://192.168.4.97/ait/Hi-AIT-123' # esp32 AiThinker

    vid = cv2.VideoCapture(url) # open webcam capture, http-based streaming. Not RTSP

    while True:
        ret, frame = vid.read() # get frame-by-frame
        #print(vid.isOpened(), ret)
        if frame is not None:
            if dropped > 0: dropped = 0 # reset
            frame, faces = face.findFaces(frame)
            # if faces:
            #    do other face processing
            cv2.imshow('Faces',frame) # display frame
            if cv2.waitKey(22) & 0xFF == ord('q'): # press q to quit
                break
        else:
            dropped += 1
            if dropped > 100:
            print("Server is down")
            break

    # Done, clear all resources
    vid.release()
    cv2.destroyAllWindows()
    print("Video stop")

## hands detection 

    # run this on Linux PC with opencv-python module

    import cv2
    from cvzone.HandTrackingModule import HandDetector


    # Hands = HandDetector(staticMode=False, maxHands=2, modelComplexity=1, detectionCon=0.5, minTrackCon=0.5)
    Hands = HandDetector(detectionCon=0.5) 
    # if not detected try move your hands away from the camera

    # Change this to your board IP
    # Try first with web-browser, you will see image stream if OK
    # http-based image streaming server

    # url = 'http://192.168.4.74/free/Hi-Nove-La' # freenove
    # url = 'http://192.168.4.70/xiao/Hi-Xiao-Ling' # xio
    # url = 'http://192.168.4.71/lily/Hi-Lily-Goen' # lilygo
    url = 'http://192.168.4.97/ait/Hi-AIT-123' # esp32 AiThinker

    vid = cv2.VideoCapture(url) # open webcam capture

    dropped = 0 # drop frames count
    while True:
        ret, frame = vid.read() # get frame-by-frame
        if frame is not None:
        if dropped > 0: dropped = 0 # reset
        hands, frame = Hands.findHands(frame, draw=True, flipType=True)
        # Check if any hands are detected
        if hands:
            # Information for the first hand detected
            hand1 = hands[0]  # Get the first hand detected
            # lmList1 = hand1["lmList"]  # List of 21 landmarks for the first hand
            bbox1 = hand1["bbox"]  # Bounding box around the first hand 
                                    # (x,y,w,h coordinates)
            center1 = hand1['center']  # Center coordinates of the first hand
            handType1 = hand1["type"]  # Type of the first hand ("Left" or "Right")

            # Count the number of fingers up for the first hand
            # fingers1 = Hands.fingersUp(hand1)
            # print(f'H1 = {fingers1.count(1)}', end=" ") 

            # Calculate distance between specific landmarks on the first hand 
            # and draw it on the image
            # length, info, frame = Hands.findDistance(lmList1[8][0:2], lmList1[12][0:2], frame, color=(255, 0, 255), scale=10)

            # Check if a second hand is detected
            if len(hands) == 2:
                # Information for the second hand
                hand2 = hands[1]
                # lmList2 = hand2["lmList"]
                bbox2 = hand2["bbox"]
                center2 = hand2['center']
                handType2 = hand2["type"]

                # Count the number of fingers up for the second hand
                # fingers2 = Hands.fingersUp(hand2)
                # print(f'H2 = {fingers2.count(1)}', end=" ")

                # Calculate distance between the index fingers of both hands 
                # and draw it on the image
                # length, info, frame = Hands.findDistance(lmList1[8][0:2], lmList2[8][0:2], frame, color=(255, 0, 0), scale=10)

            # print(" ")  # New line for better readability of the printed output
        # show image
        cv2.imshow('Hands',frame) # display frame
        # define abort key
        if cv2.waitKey(22) & 0xFF == ord('q'): # press q to quit
            break
        else:
            dropped += 1
            if dropped > 100:
            print("Server is down")
            break

    # Done, clear all resources
    vid.release()
    cv2.destroyAllWindows()
    print("Video stop")

