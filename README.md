# 📘 Problem-Solving
## 문제 풀기
- 어떤 문제를 잘 이해했다 라는건. 문제 지문만 보고 이 문제를 풀 수 있는 로직이 떠올라야 하는 것.
- 그 로직을 떠올릴 수 있다는 건, 설명할 수 있다는 것.
- 즉, 설명가능 해야 함...!
- 코드를 보고 설명하는게 아님
  
## 📝 Introduction
+ 백준, 프로그래머스, 실전프로그래밍 등등 여러 문제를 풀고 배운것을 기록합니다.
+ 또한, 중간중간 만나는 CS지식, 툴 사용법 등도 기록합니다.
+ 유용한 글
  + [티스토리 블로그 - 알고리즘 공부를 어떻게 시작해야할까? (Feat. 백준 500문제 푼 기념으로 적는 PS 회고록)](https://steady-coding.tistory.com/260)
  + [알고리즘 문제풀이(PS) 시작하기](https://plzrun.tistory.com/entry/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%AC%B8%EC%A0%9C%ED%92%80%EC%9D%B4PS-%EC%8B%9C%EC%9E%91%ED%95%98%EA%B8%B0)
  + [자료구조와 알고리즘 공부 로드맵](https://roadmap.sh/datastructures-and-algorithms)

## 📚 Table of Contents
- [ 2025-03-30 - 준비 ] ([/docs/2025-03-30.md](./docs/2025-03-30.md))
- [ 2025-04-07 ] ([/docs/2025-04-07.md](./docs/2025-04-07.md))
- [ 2025-04-10 ] ([/docs/2025-04-10.md](./docs/2025-04-10.md))
- [ 2025-04-13 ] ([/docs/2025-04-13.md](./docs/2025-04-13.md))
- [ 2025-04-14 ] ([/docs/2025-04-14.md](./docs/2025-04-14.md))
- [ 2025-04-15 ] ([/docs/2025-04-15.md](./docs/2025-04-15.md))
- [ 2025-04-16 ] ([/docs/2025-04-16.md](./docs/2025-04-16.md))

## 💡 Tips
### 1. VScode 초기세팅
✅ 1. VSCode 설치

✅ 2. C++ 컴파일러 설치
+ MYSY2 설치
  > https://www.msys2.org/
+ 사이트에서 installer찾아서 설치, 경로 수정 할 필요 없음.
+ 설치하면 여러 터미널이 보이는데, 그 중 **MSYS2 MINGW64** 터미널 실행
+ 아래 명령어를 입력하여 최신 컴파일러 도구 모음을 설치(명령어 입력 -> 엔터 -> Y입력)
  ```Bash
  pacman -S mingw-w64-x86_64-toolchain
  ```
+ 설치가 완료되면 g++ --version을 입력하여 버전이 잘 나오는지 확인
+ 환경변수 등록
  + 윈도우 검색창에 **"시스템 환경 변수 편집"**
  + **"시스템 변수"** 목록에서 Path를 찾아 **"편집"** 누르기  
  + "새로 만들기"를 클릭하고 아래 경로 입력
    > C:\msys64\mingw64\bin
  + 해당 경로를 맨 위로 이동

✅ 3. git 설치
> https://junesker.tistory.com/95
  
✅ 4. VSCode 확장 프로그램 설치
+ vs설치 및 기본 세팅
> https://velog.io/@jjoung-2j/Visual-Studio-Code-%EC%84%A4%EC%B9%98-%EB%B0%8F-%EC%84%A4
+ vscode c++ 세팅
> https://velog.io/@watermeloncrane/vscode%EC%97%90%EC%84%9C-CC-%EC%84%B8%ED%8C%85-%EC%89%AC%EC%9B%80
+ Code Runner 도 설치
> https://y-dev.tistory.com/26


✅ 5. C++ 파일 작성 & 실행
+ 아래 명령어로 컴파일하고 실행:
```
g++ hello.cpp -o hello
./hello   # (Windows에선 hello.exe)
```

✅ 6. 자동 빌드 & 디버그 설정
(이 레포 안에 있는거 그대로 가져가기)
+ .vscode 폴더 만들고, 다음 파일 생성:
  + tasks.json (컴파일 자동화용)
  + launch.json (디버깅 설정용)

✅ 7. bits/stdc++.h
1. 루트폴더에 /bits/stdc++.h 생성(stdc++.h 다운로드 https://hkhan.tistory.com/36)
2. Ctrl + Shift + P → "C/C++: Edit Configurations (UI)" → 하단 "Edit in settings.json" → c_cpp_properties.json 클릭 → .vscode/c_cpp_properties.json가 생성될것임.
3. c_cpp_properties.json 아래 코드와 같이 수정
```json
{
  "configurations": [
    {
      "name": "MinGW-w64",
      "includePath": [
        "${workspaceFolder}/**",
        "C:/msys64/mingw64/include"
      ],
      "defines": [],
      "compilerPath": "C:/msys64/mingw64/bin/g++.exe",
      "cStandard": "c17",
      "cppStandard": "c++17",
      "intelliSenseMode": "windows-gcc-x64"
    }
  ],
  "version": 4
}
```
+ vscode 터미널에 g++ --version 입력하여 컴파일러 버전 확인

✅ 8. boj 용 C++ Snippets 설정 (선택) : boj를 입력하고 Tab을 누르면 탬플릿 자동완성

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
    "    // 알고리즘 문제 풀이 시작",
    "",
    "    return 0;",
    "}"
  ],
  "description": "백준 등 알고리즘 기본 템플릿"
}
```

✅ 9. .md 용 markdown Snippets 설정 (선택) : mdlog를 입력하고 crtl+space를 누르면 탬플릿 자동완성

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
✅ 10. auto save 설정   
1. VS Code에서 단축키 Ctrl + , (콤마)를 눌러 설정(Settings) 창을 엽니다.   
2. 맨 위 검색창에 Auto Save라고 검색합니다.   
3. Files: Auto Save 항목을 off에서 afterDelay로 변경합니다.

✅ 11. VSCode 탐색기에서 .exe 숨김 설정 + gitignore
1. Ctrl + Shift + P → Preferences: Open Workspace Settings (JSON) 검색
2. 중괄호 안에 아래 코드 붙여넣고 ctrl+s로 세이브
```json
{
  "files.exclude": {
    "**/*.exe": true
  }
}
```
3. .gitignore에 exe무시 추가
```bash
# .gitignore
*.exe
```

✅ 12. json파일을 읽기 위한 nlohmann/json.hpp 추가
https://maloveforme.tistory.com/212

---
### 🤖 2. VScode GitHub Copilot 켜고 끄는 방법:
1. 설정 열기 (Ctrl + Shift + P)
2. Copilot: Enable or Copilot: Disable 입력
---
### git
```bash
git add .   
git commit -m "message"
git push
```