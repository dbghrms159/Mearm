# Mearm
아두이노 나노와 서보 모터를 이용하여 팔 제작


# processing3 를 이용한 조작 ui
  ![image](https://user-images.githubusercontent.com/38156821/44375160-1fc64900-a52d-11e8-9e8d-aafcafd847fb.png)
  <br><br>
  위의 사진과 같이 GUIProcessing 을 이용을 하여  Mearm의 방향을 제어할 2개의 GStick과 Mearm의 집게손을 제어할 1개의 Switch를 만들어 준다. GStick중 하나는 getPosition() 메소드를 이용하여 4가지 방향을 return하고 남은 하나는 getStickY() 메소드를 이용을 하여 상, 하의 값을 return을 리턴을 한다. 그 return한 값을 Serial을 통해 arduino로 보내준다. 그런데 getPosition() 메소드와 getStickY() 메소드와 return한 값 중 -1, 0, 1이 중복이 되는 관계로 getStickY() 메소드의 return값에 10을 더해 Serial통신을 하는 방법을 선택을 했다.
Switch는 클릭했을 경우에 값은 getPosition() 메소드와 getStickY() 값이 겹쳐지지 않는 7을 Serial 통신으로 arduino로 보내준다.
