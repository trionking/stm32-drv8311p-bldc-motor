# MCP 서버 활성화 문제 해결 가이드

## 증상

Claude Code에서 `.mcp.json`에 6개의 MCP 서버를 설정했지만, 실제로는 2개(ide 관련)만 활성화되는 문제

## 원인 분석

### 1. Git 저장소 미초기화
- MCP git 서버는 Git 저장소가 초기화되어 있어야 정상 작동
- `.git` 폴더가 없으면 git 관련 MCP 서버가 시작 실패

### 2. Python 패키지 실행 경로 문제
- `pymupdf4llm-mcp` 패키지의 경우 `-m` 옵션으로 실행 불가
- CLI 명령어로 직접 실행해야 함

### 3. 필수 패키지 미설치
- Python 및 npm 패키지가 제대로 설치되지 않은 경우

## 해결 방법

### 1단계: Git 저장소 초기화

프로젝트 디렉토리에서 Git이 초기화되지 않은 경우:

```bash
git init
git add .
git commit -m "Initial commit"
```

### 2단계: 필수 패키지 설치 확인

#### Python 패키지 확인:
```bash
pip show mcp-server-git mcp-server-fetch pymupdf4llm-mcp
```

설치되지 않은 경우:
```bash
pip install mcp-server-git mcp-server-fetch pymupdf4llm-mcp
```

#### npm 패키지 확인:
```bash
npm list -g | grep modelcontextprotocol
```

설치되지 않은 경우:
```bash
npm install -g @modelcontextprotocol/server-filesystem
npm install -g @modelcontextprotocol/server-memory
npm install -g @modelcontextprotocol/server-sequential-thinking
```

### 3단계: .mcp.json 설정 수정

`pymupdf4llm` 서버의 명령어를 수정:

**수정 전:**
```json
"pymupdf4llm": {
  "command": "python",
  "args": [
    "-m",
    "pymupdf4llm_mcp"
  ],
  "description": "PDF processing and text extraction with PyMuPDF4LLM"
}
```

**수정 후:**
```json
"pymupdf4llm": {
  "command": "pymupdf4llm-mcp",
  "args": [],
  "description": "PDF processing and text extraction with PyMuPDF4LLM"
}
```

### 4단계: Claude Code 재시작

모든 수정 완료 후:
1. Claude Code 완전 종료
2. Claude Code 재시작
3. MCP 서버 활성화 상태 확인

## 검증 방법

### MCP 도구 목록 확인

Claude Code에서 다음과 같이 요청:
```
mcp 활성화 상태를 확인해줘
```

정상적으로 활성화된 경우 다음 MCP 도구들이 보여야 함:
- `mcp__filesystem__*` - 파일시스템 작업
- `mcp__git__*` - Git 작업
- `mcp__memory__*` - 메모리/컨텍스트 관리
- `mcp__fetch__*` - 웹 페치
- `mcp__pymupdf4llm__*` - PDF 처리
- `mcp__ide__*` - IDE 통합

### 패키지 실행 테스트

각 MCP 서버가 정상 작동하는지 확인:

```bash
# Git MCP 서버
python -m mcp_server_git --help

# Fetch MCP 서버
python -m mcp_server_fetch --help

# PyMuPDF4LLM MCP 서버
pymupdf4llm-mcp --help

# Filesystem MCP 서버 (npx는 자동으로 실행)
npx -y @modelcontextprotocol/server-filesystem --help
```

## 일반적인 문제들

### 문제 1: "Git repository not initialized" 오류
**해결:** `git init` 실행

### 문제 2: "Module not found" 오류
**해결:** 해당 Python/npm 패키지 재설치

### 문제 3: Windows 경로 문제
**해결:** `.mcp.json`에서 경로를 이스케이프된 백슬래시(`\\`) 사용
```json
"D:\\work\\project\\path"
```

### 문제 4: MCP 서버가 계속 2개만 활성화
**해결 순서:**
1. Git 초기화 확인
2. 패키지 설치 확인
3. `.mcp.json` 설정 검토
4. Claude Code 완전 재시작 (프로세스 강제 종료 후 재시작)

## 완전한 .mcp.json 예제

```json
{
  "mcpServers": {
    "filesystem": {
      "command": "npx",
      "args": [
        "-y",
        "@modelcontextprotocol/server-filesystem",
        "D:\\work\\project\\path"
      ],
      "description": "Secure file operations for project directory"
    },
    "git": {
      "command": "python",
      "args": [
        "-m",
        "mcp_server_git",
        "--repository",
        "D:\\work\\project\\path"
      ],
      "description": "Git repository management"
    },
    "memory": {
      "command": "npx",
      "args": [
        "-y",
        "@modelcontextprotocol/server-memory"
      ],
      "description": "Knowledge graph-based persistent memory"
    },
    "sequential-thinking": {
      "command": "npx",
      "args": [
        "-y",
        "@modelcontextprotocol/server-sequential-thinking"
      ],
      "description": "Dynamic problem-solving"
    },
    "fetch": {
      "command": "python",
      "args": [
        "-m",
        "mcp_server_fetch"
      ],
      "description": "Web content fetching"
    },
    "pymupdf4llm": {
      "command": "pymupdf4llm-mcp",
      "args": [],
      "description": "PDF processing"
    }
  }
}
```

## 참고사항

- MCP 서버는 Claude Code 시작 시 자동으로 로드됩니다
- 설정 변경 후 반드시 Claude Code를 재시작해야 합니다
- 각 MCP 서버는 독립적으로 작동하며, 하나가 실패해도 다른 서버에는 영향을 주지 않습니다
- Windows 환경에서는 Python 및 npm의 PATH 설정이 올바른지 확인하세요

## 추가 디버깅

문제가 계속되면:

1. **환경 변수 확인:**
   ```bash
   echo %PATH%
   python --version
   node --version
   npm --version
   ```

2. **각 명령어 개별 테스트:**
   ```bash
   python -m mcp_server_git --help
   pymupdf4llm-mcp --help
   npx -y @modelcontextprotocol/server-filesystem
   ```

3. **Claude Code 로그 확인:**
   - Claude Code의 로그 출력에서 MCP 서버 시작 실패 메시지 확인
   - 각 서버의 에러 메시지 분석

---

**작성일:** 2025-11-20
**버전:** 1.0
**적용 프로젝트:** STM32H743 BLDC 제어 펌웨어
