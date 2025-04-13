# 📘 Problem-Solving
## 📝 Introduction
+ 백준, 프로그래머스, 실전프로그래밍 등등 여러 문제를 풀고 배운것을 기록합니다.
+ 또한, 중간중간 만나는 CS지식, 툴 사용법 등도 기록합니다.
+ 유용한 글
  + [티스토리 블로그 - 알고리즘 공부를 어떻게 시작해야할까? (Feat. 백준 500문제 푼 기념으로 적는 PS 회고록)](https://steady-coding.tistory.com/260)
  + [알고리즘 문제풀이(PS) 시작하기](https://plzrun.tistory.com/entry/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%AC%B8%EC%A0%9C%ED%92%80%EC%9D%B4PS-%EC%8B%9C%EC%9E%91%ED%95%98%EA%B8%B0)
  + [자료구조와 알고리즘 공부 로드맵](https://roadmap.sh/datastructures-and-algorithms)

## 📚 Table of Contents
- [ 2025-03-30 - 준비 ] ([/docs/2025-03-30.md](./docs/2025-03-30.md))

## 💡 Tips
### 1. VScode 초기세팅
✅ 1. VSCode 설치

✅ 2. C++ 컴파일러 설치
+ MinGW 설치
> https://m.blog.naver.com/dorergiverny/223032334186

✅ 3. VSCode 확장 프로그램 설치
+ vs설치 및 기본 세팅
> https://velog.io/@jjoung-2j/Visual-Studio-Code-%EC%84%A4%EC%B9%98-%EB%B0%8F-%EC%84%A4
+ Code Runner 도 설치
> https://y-dev.tistory.com/26

✅ 4. C++ 파일 작성 & 실행
+ 아래 명령어로 컴파일하고 실행:
```
g++ hello.cpp -o hello
./hello   # (Windows에선 hello.exe)
```

✅ 5. 자동 빌드 & 디버그 설정
(이 레포 안에 있는거 그대로 가져가기)
+ .vscode 폴더 만들고, 다음 파일 생성:
  + tasks.json (컴파일 자동화용)
  + launch.json (디버깅 설정용)

✅ 6. bits/stdc++.h
1. 루트폴더에 /bits/stdc++.h 생성(stdc++.h 다운로드 https://hkhan.tistory.com/36)
2. Ctrl + Shift + P → "C/C++: Edit Configurations (UI)" → 하단 "Edit in settings.json" → c_cpp_properties.json 클릭 → .vscode/c_cpp_properties.json가 생성될것임.
3. c_cpp_properties.json 아래 코드와 같이 수정
```json
{
  "configurations": [
    {
      "name": "Win32",
      "includePath": [
        "${workspaceFolder}/**",
        "${workspaceFolder}/bits"  // 🔥 이 줄을 추가
      ],
      "defines": [],
      "compilerPath": "C:/MinGW/bin/g++.exe", // 🔥 cl.exe 에서 g++ 경로로 수정
      "cStandard": "c17",
      "cppStandard": "c++17",
      "intelliSenseMode": "windows-gcc-x64" // 🔥 msvc에서 gcc로 수정
    }
  ],
  "version": 4
}
```

✅ 7. boj 용 C++ Snippets 설정 (선택) : boj를 입력하고 Tab을 누르면 탬플릿 자동완성

1. ctrl + shift + P 눌러 커맨드 팔레트 켜기
2. "Preferences: Configure User Snippets" 검색
3. 언어 목록에서 C++ 선택
4. cpp.json의 중괄호 안에 아래 코드 붙여넣고 ctrl+s로 세이브
```json
"Algorithm Template": {
  "prefix": "boj",
  "body": [
    "/***********************************************",
		" * ${CURRENT_YEAR}-${CURRENT_MONTH}-${CURRENT_DATE}",
		" ***********************************************/",
		"",
    "#include <bits/stdc++.h>",
    "using namespace std;",
    "",
    "#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);",
    "#define endl '\\n'",
    "",
    "int main() {",
    "    fastio;",
    "",
    "    // 알고리즘 문제 풀이 시작",
    "    return 0;",
    "}"
  ],
  "description": "백준 등 알고리즘 기본 템플릿"
}
```

✅ 8. .md 용 markdown Snippets 설정 (선택) : mdlog를 입력하고 crtl+space를 누르면 탬플릿 자동완성

1. ctrl + shift + P 눌러 커맨드 팔레트 켜기
2. "Preferences: Configure User Snippets" 검색
3. 언어 목록에서 markdown 선택
4. markdown.json의 중괄호 안에 아래 코드 붙여넣고 ctrl+s로 세이브
```json
"Problem Log Template": {
  "prefix": "mdlog",
  "body": [
    "# [Problem]",
    "",
    "# [ Overview ]",
    "",
    "# [ INDEX ]",
    "",
    "# [ MAIN LOG ]",
    "### 1. title",
    "",
  ],
  "description": "알고리즘 문제 정리용 마크다운 템플릿"
}
```

### 🤖 2. VScode GitHub Copilot 켜고 끄는 방법:
1. 설정 열기 (Ctrl + Shift + P)
2. Copilot: Enable or Copilot: Disable 입력

