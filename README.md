# Mearm
아두이노 나노와 서보 모터를 이용하여 팔 제작

# 조작과정
  Serial 통신을 하여 Mearm의 servo모터를 움직인다.<br>
  Serial 통신으로 조작을 하기위해 GUIProcessing의 GSrick을 이용하여 스틱이 이동되었다는 신호를 보낸다<br>
  아두이노에서는 GUIProcessing에사 스틱이 이동됬다는 통신이 오면 그 움직인 만큼 servo 모터의 각을 움직여 준다

# processing3 를 이용한 조작 ui
  ![image](https://user-images.githubusercontent.com/38156821/44375160-1fc64900-a52d-11e8-9e8d-aafcafd847fb.png)
  <br><br>
  위의 사진과 같이 GUIProcessing 을 이용을 하여  Mearm의 방향을 제어할 2개의 GStick과 Mearm의 집게손을 제어할 1개의 Switch를 만들어 준다. GStick중 하나는 getPosition() 메소드를 이용하여 4가지 방향을 return하고 남은 하나는 getStickY() 메소드를 이용을 하여 상, 하의 값을 return을 리턴을 한다. 그 return한 값을 Serial을 통해 arduino로 보내준다. 그런데 getPosition() 메소드와 getStickY() 메소드와 return한 값 중 -1, 0, 1이 중복이 되는 관계로 getStickY() 메소드의 return값에 10을 더해 Serial통신을 하는 방법을 선택을 했다.
Switch는 클릭했을 경우에 값은 getPosition() 메소드와 getStickY() 값이 겹쳐지지 않는 7을 Serial 통신으로 arduino로 보내준다.
